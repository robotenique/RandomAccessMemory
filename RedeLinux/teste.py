import subprocess as sbp
x = sbp.run("groups | grep -q juliano",shell=True)
print(x)
