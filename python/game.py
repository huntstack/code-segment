#encoding:utf-8

import random

display = "\n请选择游戏类别:\n1.剪刀石头布\n2.猜价格\n"
print display

def finger_guess():
	guess_list = ["石头","剪刀","布"]
	win = [["布","石头"],["石头","剪刀"],["剪刀","布"]]
	while True:
		c = random.choice(guess_list)
		p =  raw_input('请输入：石头,剪刀,布:').strip()
	  	if p == "exit":
	  		print display
	  		break	
	  	elif p not in guess_list:
	  		print "输入非法"
		elif c ==  p:
	  		print "平,再来"
	  	elif [c,p] in win :
	  		print "输:("
	  	else: 
	  		print "恭喜!赢:)"

def price_guess():
	good_list = ["平底锅","连衣裙","iphone","充电器","香蕉"]
	price_list = [i for i in range(10000) if i%10 != 0]
	while True:
		s = raw_input("请输入【"+random.choice(good_list)+"的价格】:").strip()
		price  = random.choice(price_list)
		if s == "exit":
			print display
			break
		elif not s.isdigit():
			print "价格肯定是数字啊少年"
		else:
			res = process(int(s),price)
			while not res:
				s = raw_input().strip()
				res = process(int(s),price)

def process(p,price):
	if p<price:
		print "便宜了"
		return False
	elif p>price:
		print "贵了"
		return False
	elif p == price:
		print "bingo!"
		return True

while True:
	input_str = raw_input("输入编号:").strip()
	if input_str == '1':
		finger_guess()
	elif input_str == '2':
		price_guess()
	elif input_str == 'q':
		break
	else:
		print "别乱输，看提示^_^\n"