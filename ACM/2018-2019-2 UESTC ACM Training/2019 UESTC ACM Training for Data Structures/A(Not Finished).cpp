#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007ll
#define M(x) (x+mod)%mod
using namespace std;

const LL maxn = 200000;

LL a[maxn] = { 0 }; //starts with 1

struct nodeStruct {
	LL v, vs, mul, add;
	nodeStruct operator + (nodeStruct b)
	{
		return nodeStruct{ v + b.v, vs + b.vs };
	}
}node[maxn << 2];//vs: sigma(v^2)


//Full binary tree
//root == 1
//left=father*2, right=father*2+1 

void build(LL root, LL l, LL r)
{
	node[root].add = 0;
	node[root].mul = 1;

	if (l == r)
	{
		node[root].v = M(a[l]);
		node[root].vs = M(node[root].v * node[root].v);
	}
	else
	{
		LL m = (r + l) / 2;
		build(root * 2, l, m);
		build(root * 2 + 1, m + 1, r);
		node[root].v = M(node[root * 2].v + node[root * 2 + 1].v);
		node[root].vs = M(node[root * 2].vs + node[root * 2 + 1].vs);
	}
}

//push father's tag down to sons' value and tag
LL push_down(LL root, LL l, LL r)
{
	LL m = (l + r) / 2;
	LL a = node[root].mul, b = node[root].add;

	//update sons' value
	//sigma((ax+b)^2) = a^2*sigma(x^2)+2ab*sigma(x)+n*b^2
	//calculating sigma((ax+b)^2) needs old sigma(x), so it should be first
	node[root * 2].vs = M(M(a * a) * node[root * 2].vs 
		+ M(2 * a * b)*node[root * 2].v
		+ M(b * b)*(m - l + 1));
	node[root * 2 + 1].vs = M(M(a * a) * node[root * 2 + 1].vs
		+ M(2 * a*b)*node[root * 2 + 1].v 
		+M(b * b)*(r - m));
	
	//sigma(ax+b) = a*sigma(x)+b*n
	node[root * 2].v = M(a * node[root * 2].v + b * (m - l + 1));
	node[root * 2 + 1].v = M(a * node[root * 2 + 1].v + b * (r - m));

	//update sons' tag
	//a(cx+d)+b = acx + ad + b
	node[root * 2].mul = M(a * node[root*2].mul);
	node[root * 2].add = M(a * node[root * 2].add + b);
	node[root * 2+1].mul = M(a * node[root * 2+1].mul);
	node[root * 2+1].add = M(a * node[root * 2+1].add + b);


	//reset father's tag
	node[root].mul = 1;
	node[root].add = 0;

	return 0;
}

// plus
void update1(LL root, LL curl, LL curr, LL l, LL r, LL k)
{
	//the same to update2()
	if (curr < l || r < curl)
		return;

	if (l <= curl && curr <= r)
	{
		//sigma((x+k)^2) = sigma(x^2)+2k*sigma(x)+n*k^2
		node[root].vs = M(node[root].vs + M(2 * k*node[root].v) + (curr-curl+1) * M(k*k));
		node[root].v = M(node[root].v + k * (curr - curl + 1));
		// multiple current l&r, not input l&r
		node[root].add = M(node[root].add + k);
		return;
	}
	
	push_down(root, curl, curr);

	LL m = (curl + curr) / 2;
	update1(root * 2, curl, m, l, r, k);
	update1(root * 2 + 1, m + 1, curr, l, r, k);

	node[root].v = M(node[root * 2].v + node[root * 2 + 1].v);
	node[root].vs = M(node[root * 2].vs + node[root * 2 + 1].vs);
	return;
}


// multiply; curl & curr: going to modify; l & r: input range
void update2(LL root, LL curl, LL curr, LL l, LL r, LL k)
{
	//if the two range has no intersection, return
	if (curr < l || r < curl)
		return;

	// if the input range include the current range, just update the father and return
	if (l <= curl && curr <= r)
	{
		//sigma((cx)^2) = c^2*sigma(x^2)
		node[root].vs = M(node[root].vs * M(k * k));

		//sigma(cx)=c*sigma(x)
		node[root].v = M(node[root].v * k);

		//c*(ax+b)=acx+bc
		node[root].add = M(node[root].add * k);
		node[root].mul = M(node[root].mul * k);
		return;
	}

	//push down the tag first
	//because we're going to modify sons' value and tag
	//and sons' tags are earlier than father's
	push_down(root, curl, curr);

	//update sons
	LL m = (curl + curr) / 2;
	update2(root * 2, curl, m, l, r, k);
	update2(root * 2+1, m + 1, curr, l, r, k);
	
	//don't forget to update father's value
	node[root].v = M(node[root * 2].v + node[root * 2 + 1].v);
	node[root].vs = M(node[root * 2].vs + node[root * 2 + 1].vs);
	return;
}

nodeStruct query(int root, int curl, int curr, int l, int r)
{
	if (curr < l || r < curl)
		return { 0,0 };
	if (l <= curl && curr <= r)
		return node[root];

	push_down(root, curl, curr);
	int m = (curl + curr) / 2;
	return query(root * 2, curl, m, l, r) + query(root * 2 + 1, m + 1, curr, l, r);
}
//S^2=n*sigma(x^2)-sigma(x)^2

LL n, q, o, x, y, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (LL i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	build(1,1,n);

	for (LL i = 0; i < q; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x >> y >> k;
			update1(1, 1, n, x, y, k);
		}
		else if (o == 2)
		{
			cin >> x >> y >> k;
			update2(1, 1, n, x, y, k);
		}
		else if (o == 3)
		{
			cin >> x >> y >> k;
			update2(1, 1, n, x, y, 0);
			update1(1, 1, n, x, y, k);
		}
		else if (o == 4)
		{
			cin >> x >> y;
			nodeStruct ans = query(1, 1, n, x, y);
			cout << M(M((y-x+1)*ans.vs) - M(ans.v*ans.v)) << endl;
		}
		else if (o == 5)
		{
			cin >> x >> y;
			cout << query(1, 1, n, x, y).v << endl;
		}
	}
	return 0;
}
