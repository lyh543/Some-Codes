import json
import os.path
import re
from typing import List

PACKAGE_LIST_TXT = 'package-list.txt'
PACKAGE_WHITE_LIST = [
    'com.android',
    'com.google',
]
OUTPUT_JSON = 'DeepSleep-backup.json'


def get_package_list() -> List[str]:
    if os.path.exists(PACKAGE_LIST_TXT):
        with open(PACKAGE_LIST_TXT, 'r') as file:
            package_list = file.readlines()
            package_list = list(map(lambda s: s.strip(), package_list))
            return package_list
    return []


def filter_package_list(origin_package_list: List[str]) -> List[str]:
    filtered_list = origin_package_list
    for white_pattern in PACKAGE_WHITE_LIST:
        filtered_list = list(filter(lambda s: white_pattern not in s, filtered_list))
    return list(filtered_list)


def gen_json(package_list: List[str]):
    app_sts = []
    for package_name in package_list:
        app_sts1 = {
            "alarm": True,
            "broadcast": False,
            "flag": True,
            "service": True,
            "sync": True,
            "wakelock": True,
            "packageName": package_name
        }
        app_sts.append(app_sts1)
    config = {
        "appSts": app_sts,
        "extends": []
    }
    with open(OUTPUT_JSON, 'w') as file:
        json.dump(config, file)


if __name__ == '__main__':
    package_list = get_package_list()
    filtered_package_list = filter_package_list(package_list)
    gen_json(filtered_package_list)
