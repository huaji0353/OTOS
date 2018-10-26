#coding:utf-8
import sys, subprocess

# C compile workflow
# 翻译
CC1 = "CC1"
# 汇编
GAS2NASK = "GAS2NASK"
NASK = "NASK" # -> .lst
# 链接
OBJ2BIM = "OBJ2BIM" # -> .map
BIM2HRB = "BIM2HRB"

def execc(command):
	sp = subprocess.Popen(command, stdout=subprocess.PIPE)
	#print sp.communicate()[0]

for i in range(10):
	execc("ping 127.0.0.1")