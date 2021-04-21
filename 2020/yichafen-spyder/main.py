# 介绍可见 https://lyh543.github.io/python/selenium/
from selenium import webdriver
import time
import sys

url = "https://240334.yichafen.com/public/queryscore/sqcode/OsTcknwmMjkzfGZlYWYyOTQ1YjA5YmM1ZTQxOGQzMmY1NTdiYzNlYjI2fDI0MDMzNAO0O0OO0O0O.html"


def get_score(name: str, student_id: str) -> str:
    driver.implicitly_wait(1)
    driver.get(url)
    driver.refresh()

    student_id_element = driver.find_element_by_xpath("//input[@name='s_xuehao']")
    student_id_element.clear()
    student_id_element.send_keys(student_id)
    name_element = driver.find_element_by_xpath("//input[@name='s_xingming']")
    name_element.clear()
    name_element.send_keys(name)

    button = driver.find_element_by_xpath("//*[@id='yiDunSubmitBtn']")
    button.click()
    driver.implicitly_wait(0.5)

    try:
        assert (driver.find_element_by_xpath("//*[@id='result_content']/div[2]/table/tbody/tr[2]/td[1]").get_attribute(
            "innerHTML") == student_id)
        assert (driver.find_element_by_xpath("//*[@id='result_content']/div[2]/table/tbody/tr[2]/td[2]").get_attribute(
            "innerHTML") == name)
    except:
        raise ValueError("%s %s 信息不对应" % (name, student_id))
    return driver.find_element_by_xpath("//*[@id='result_content']/div[2]/table/tbody/tr[2]/td[3]").get_attribute(
        "innerHTML")


if __name__ == '__main__':
    driver = webdriver.Chrome()
    skip = False
    if len(sys.argv) == 2:
        skip = True
    with open('input.csv') as input:
        for line in input:
            if skip:
                if sys.argv[1] not in line:
                    continue
                else:
                    skip = False
            name, student_id = line.strip().split(',')
            score = get_score(name, student_id)
            print("%s,%s,%s" % (name, student_id, score))
            with open('output.csv', 'a+') as output:
                output.write("%s,%s,%s\n" % (name, student_id, score))
