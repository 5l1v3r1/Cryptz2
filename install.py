import os, time
if os.getuid() != 0:
	exit("\033[31m" + "Please run this as root, or use sudo!" + "\033[0m")
os.system("apt-get update")
os.system("apt-get install python3")
os.system("apt-get install python3-pip")
os.system("pip3 install pybase64")
os.system("pip3 install base64")
print("You can run this by using: python3 cryptz.py")
sleep(3)
os.system("python3 cryptz.py")
