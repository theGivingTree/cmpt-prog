import subprocess
import sys

def popc(i):
    i = i - ((i >> 1) & 0x55555555)
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
    return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24

MAX_N = 31 
cmb=[0]*(MAX_N+1)
cmb[0]=1
for N in range(31, MAX_N+1):
    cmb[N]=1
    for r in range(1, N):
        cmb[r]=cmb[r-1]*(N-r+1)//r;
    for r in range(1, N+1):
        cmb[r] += cmb[r-1]
    for L in range(1, N+1):
        print(f'...test when L={L}');
        last = -1;
        for I in range(1, cmb[L]+1):
            complete = subprocess.run('./run.out', input=f'{N} {L} {I}', encoding='utf-8', stdout=subprocess.PIPE)
            ou = complete.stdout
            size = len(ou)
            val = int(complete.stdout, 2)
            #print(complete.stdout)
            if(size != N or last >= val or popc(val)>L):
                print(f'input: {N} {L} {I}')
                print(f'{ou} != {N}')
                print('---loser...')
                sys.exit()
            last = val
