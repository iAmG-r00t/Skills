# C strings & `/proc`

## Resources

- [Holberton Part 1](https://github.com/holbertonschool/Hack-The-Virtual-Memory/tree/master/00.%20C%20strings%20%26%20the%20proc%20filesystem)
- [Introduction to memory management in Linux](https://www.youtube.com/watch?v=7aONIVSXiJ8)
- [Virtual Memory Youtube Playlist](https://www.youtube.com/playlist?list=PLiwt1iVUib9s2Uo5BeYmwkDFUh70fJPxX)
- [/Proc Filesystem - Process](https://sonseungha.tistory.com/412)
- [How do I read from /proc/$pid/mem under Linux?](https://unix.stackexchange.com/a/6302)
- [Linux: read and write another process's memory](https://renenyffenegger.ch/notes/Linux/memory/read-write-another-processes-memory)
- [Read and Write a /proc File](https://linux.die.net/lkmpg/x769.html) The Linux Kernel Module Programming GuideChapter 5; The /proc File System
- [Diving into /proc/[pid]/mem](https://blog.cloudflare.com/diving-into-proc-pid-mem/) by Cloudflare.

---

## Video

Terminal screen recording of the code working.

[![asciicast](https://asciinema.org/a/BksQpmJJWUfDpPU2u3ZnhmjdS.svg)](https://asciinema.org/a/BksQpmJJWUfDpPU2u3ZnhmjdS)


The [main.c](./main.c) file contains the C code for this first objective, please visit the resources section; *Holberton part 1* to follow along.
- Compile the code this way: `gcc -o loop main.c`

I decided to port the python code to C; [read_write_heap.c](./read_write_heap.c) for general learning purposes. It wasn't an easy task but I managed after a very long time.
- Compile the code this way: `gcc -o read_write_heap read_write_heap.c`
