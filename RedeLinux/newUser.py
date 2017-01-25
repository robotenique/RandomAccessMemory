import string
import random as rnd
from subprocess import *
print("==> New user creator -> RUN WITH 'SUDO python newUser.py'!\nINFO:Be sure that the username doesn't exist by checking it first in /etc/passwd!")
username = input("Type the username:")
Popen(['sudo','groupadd',username])
Popen(['sudo','useradd',"-g", username, username])
st = string.ascii_letters + string.digits
pw = "".join((rnd.choice(st)) for x in range(10))
print("The user was created. You password is: ", pw)
