import hashlib
inputstring = "This is a message sent by a computer user."
output = hashlib.md5(inputstring.encode())

print("Hash of the input string:")
print(output.hexdigest())