# Generated by Selenium IDE
import pytest
import time
import json
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities

class Test04DelDept():
  def setup_method(self, method):
    self.driver = webdriver.Chrome()
    self.vars = {}
  
  def teardown_method(self, method):
    self.driver.quit()
  
  def test_04DelDept(self):
    # Test name: 04DelDept
    # Step # | name | target | value
    # 1 | open | / | 
    self.driver.get("http://122.9.143.225/")
    # 2 | setWindowSize | 1259x1080 | 
    self.driver.set_window_size(1259, 1080)
    # 3 | selectFrame | index=1 | 
    self.driver.switch_to.frame(1)
    # 4 | click | css=.layui-table-hover .layui-btn-danger | 
    self.driver.find_element(By.CSS_SELECTOR, ".layui-table-hover .layui-btn-danger").click()
    # 5 | click | linkText=确定 | 
    self.driver.find_element(By.LINK_TEXT, "确定").click()
  
