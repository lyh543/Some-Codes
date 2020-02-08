#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include <string>

using namespace std;

list<char> s;
char cmd[50];

int main()
{
	
	freopen("input.txt","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char c;
	c = getchar();
	while(c != '\n')
	{
		s.push_back(c);
		c = getchar();
	}
	
	scanf("%s",cmd);
	//cin >> cmd;
	while (strcmp(cmd,"quit"))
	{
		if (!strcmp(cmd,"ins"))
		{
			getchar();	
			c = getchar();
			while(c != '\n')
			{
				s.push_back(c);
				c = getchar();
			}
		}
		else if (!strcmp(cmd,"del"))
		{
			int l, r; // Èôl=2,r=5,ÔòÉ¾³ý2-4×Ö·û
			scanf("%d%d",&l,&r);
			
			list<char>::iterator t = s.begin(), lt;
			
			for (int i = 1; i < l; i++)
				t++;
				
			lt = t;
			
			for (int i = l; i < r; i++)
				t++;
			
		}
		else if (!strcmp(cmd,"cnt"))
		{
			int tot = 0;
			char target[50];
			scanf("%s",target);
			/*for (list<char>::iterator cp = s.begin(); cp != s.end(); cp++)
			{
				if (*cp == target[0])
				{
					bool ok = true;
					list<char>::iterator temp = cp;
					temp++;
					for (int i = 1; target[i] != '\0'; i++)
					{
						if (*temp != target[i])
						{
							ok = false;
							break;
						}
						temp++;
					}
					if (ok)
					{
						tot++;
						cp = temp;
					}
				}
			}
			printf("%d\n",tot);*/
		}
		else if (!strcmp(cmd,"rep"))
		{
			;
		}
		else 
		{
			printf("Command Not Found:%s \n",cmd);
			char c = getchar();
			while(c != '\n')
			{
				c = getchar();
			}
		}
		scanf("%s",cmd);
	}
	
	for (list<char>::iterator cp = s.begin(); cp != s.end(); cp++)
		printf("%c",*cp);
	
}
