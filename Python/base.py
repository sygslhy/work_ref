# list

lst = [1, "string", 2.0, 35L]
lst = lst*2

lst.append("yuan")
print lst
del lst[2]
print lst
print len(lst)

#cmp(lst1, lst2)
#max(lst)
#min(lst)
print lst.count("yuan")
print lst.index("yuan")
lst.insert(1, "renlan")
lst.pop()
lst.remove("string")
lst.reverse()
lst.sort() #number then string
print lst

#dict
dict = {'Name': 'Zara', 'Age': 7, 'Name': 'Manni'}
print dict['Name']
#cmp(dict1, dict2)
print len(dict)
print dict
print str(dict)
dict2 = dict.copy()
print dict2
print dict.get("Age")
print dict.has_key("8")
print dict.items()
print dict.keys()

import collections
d1 = collections.OrderedDict()

print dict.values()
print dict.pop("Name")

#excpetion
"""
try:
    fh = open("testfile", "w")
    fh.write("ex")
except IOError:
    print "Error:"
else:
    print "sc"
    fh.close()
""" 

#date and time
import time
localtime = time.asctime(time.localtime(time.time()))
print localtime

#random
#import random
print( random.randint(1,10) )        # ���� 1 �� 10 ��һ�������������  
print( random.random() )             # ���� 0 �� 1 ֮������������
print( random.uniform(1.1,5.4) )     # ����  1.1 �� 5.4 ֮��������������������Բ�������
print( random.choice('tomorrow') )   # �����������ѡȡһ��Ԫ��
print( random.randrange(1,100,2) )   # ���ɴ�1��100�ļ��Ϊ2���������