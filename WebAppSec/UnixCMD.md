# :shell: Unix Shell Command Line Stuff

```bash
    In this section most of the things are more of the basics one should know when dealing with web applications mostly in unix command line.
        These things include:
            1. How to run commands.
            2. How to filter data.
            3. How manage and run database commands.
            4. Encryption stuff.
            5. Common linux commands.
            6. Other common applications like node and other common programming languages you should be familiar with.
```

&nbsp;

- **So when running multiple commands:**
  
  ```bash
          1. command1 || command2 : will run command2 if command1 fails
          2. command1 && command2 : will run command2 if command1 succeeds
          3. command1  ; command2 : will run command1 then command2
          4. command1  | command2 : will run command1 then send the output of command1 to command2
  ```

  - **The first one was new to me** the double pipes.
&nbsp;
- **Never knew you could run another command within the find command:**
  - find location -name filename -exec command-to-execute pattern {in all files} \;

    ```bash
           Example: Locate a file known as .bashrc then grep for a line with the certain word [key]

           find /home -name .bashrc -exec grep key {} \;
    ```

&nbsp;

- **Grep options;** some I knew but its good to note all of them down  
  - Remove certain lines with a specific word, use option -v:

     ```bash
            grep -v word
     ```
  
  - Grep a specific line with a certain pattern:
  
     ```bash
            grep -A 1 '^passwd'
     ```

&nbsp;

- **Encrypt and Decreypt with OpenSSL:**
  
  ```bash
         encrypt    = openssl enc -<encryption-method> -k <passwd> -in <file-to-encrypt> -out <file-to-output>

         decrypt    = openssl enc -d -<encryption-method> -k <passwd> -in <file-to-decrypt> -out <file-to-output>
  ```

&nbsp;

- **HASH Algorithms:**
  
  ```bash
          $2$ = Blowfish
          $5$ = SHA-256
          $6$ = SHA-512
          $1$ = MD5
  ```

&nbsp;

- **MYSQL Commands:**
  - connect to mysql without password:

    ```bash
        msql -u <username>
    ```

  - list databases:

    ```bash
        show databases;
    ```

  - selecting a database:

     ```bash
        use [ DATABASE ]
     ```

  - list tables:

    ```bash
       show tables;
    ```

  - view data in tables:

    ```bash
       select * from [ TABLE ];
    ```

  - using msql load_file function (can be a CTF challenge and can be used in exploitation on older systems :chipmunk:)

    ```bash
       select load_file('/file/path');
    ```

    - **Learnt something new right here.**

    - **NB**: On newer MSQL versions they have locked down, you are limited to **/var/lib** location only but on older systems you can be able to access any file at any location. 
    - **Note**: ***show*** and ***use*** command will not work in SQL injections, they are internal commands there are not part of SQL.

&nbsp;

- **POSTGRES Commands**:
  - login as postgres user:

    ```bash
       su postgres
    ```

  - connect to the local PostgreSQL database:
    - Unauthorized Way:

    ```bash
       psql
    ```

    - Authorized Way:

    ```bash
       psql -U [ USERNAME ] -W (for password)
    ```

  - list the databases: ```\list```

  - select a database: ```\c [ DATABASE ]```

  - list tables ```\d```

  - view data in tables: ```SELECT * from [ TABLE ];```

  - create table: ```CREATE TABLE demo(t text);```

  - copy file to table: ```COPY demo from '[FILENAME]';```

  - delete table: ```DROP TABLE demo;```

&nbsp;

- **SQLITE3 program:**
  - You can use it to interacte with a sqlite3 db file.
    - connect to db file: ```sqlite3 file.db```
  
    - list tables: ```.tables```

    - extract data: ```select * from [ TABLE ]```

&nbsp;

- **SUDO - Privilege Escalation:** (can be a CTF challenge :chipmunk:)
  - To see what command you are authorized to run

    ```bash
       sudo -l
    ```

  - run the command with sudo as another user

    ```bash
       sudo -u user [ command ]
    ```

&nbsp;

- **VIM - !Damned Editor!** (some of these can be used in a CTF challenge :chipmunk:)
  - read a file from the editor if you know the path

    ```bash
       :r /path/to/file
    ```

  - enter shell within vim
  
    ```bash
       :!/bin/bash
    ```

&nbsp;

- **LESS - Escalate to shell:**
  
  ```bash
    less --help then type the following command inside less [ !/bin/bash ] or just [ ! ]
  ```

  - One can also read a file inside less by specifing the full path using **:e [PATH]**

&nbsp;

- **AWK - Escalate to shell:**
  
```bash
   awk 'BEGIN {system("/bin/bash")}'
```

&nbsp;

- **Escalate privileges through setting [ setuid ] and [ setgid ]:**
  - Look at what commands the victim/user/target can run. ```sudo -l```
  - If he/she can run both **cp** and **chmod**, then you can escalate privileges.
  - You can copy the bash binary file to the user directory, set uid and gid then execute it and you will have your shell. :smile:
  - Or place the c code below in a file: (to read a file)

    ```c
       int main(void)
        {
        system("cat /home/victim/ctf-key.txt");
        }
    ```

  - Then compile it using gcc:

    ```bash
       gcc -o [FILE] [FILE].c
    ```

  - Then copy the compiled file with the ```sudo -u [ victim ] [ cp ] ....``` command to create a file owned by the victim/user/target user
  - then set the seuid and guid by running ```sudo -u [ victim ] [ chmod ] +xs ....```  command
    - x - make it executable
    - s - set userid and groupid of the user

&nbsp;

- **Escalate privileges with perl:**
  - drop to shell:

    ```bash
       perl -e '`/bin/bash`' 
    ```

  - view data of a file using perl:

    ```bash
       perl -e 'print `cat /path/to/file`'
    ```

&nbsp;

- **Escalate privileges with python:**
  - This will be done by reading file from python REPL (A Read–Eval–Print Loop).
  - Then running python to start the interactive shell, below is the code
  - Import os module then you can run the commands using os.system('cmd')

  ```bash
        import os
        os.system('cat /path/to/file') # Execute cat command to read file
        os.system('uname -a') # Execute uname command to get linux name

    # or
        from subprocess import call # import the call command from the subprocess module
        call(['cat', '/path/to/file']) # Execute the cat command to read file using the call method
  ```

&nbsp;

- **Escalate privileges with ruby:**
  - start a ruby shell/REPL to run ruby commands:

    ```bash
       ruby -e 'require "irb" ; IRB.start(__FILE__)'
    ```

  - read file inside the ruby REPL:

    ```bash
       puts `cat /path/to/file`
    ```

  - or one can use ruby -e to run a command; (where the puts command prints the value back)

    ```bash
       ruby -e 'puts `cat /path/to/file`'
    ```

&nbsp;

- **Escalate privileges with node:**
  - The payload below ran inside the node command is a JavaScript code, that uses a variable exec function/module to execute a command and uses 3 functions error, stdOut and stdErr to read the standard output using the console.log module/function. 
  - Read a file with node:

    ```bash
        node -e 'var exec = require("child_process").exec;
        exec("cat /path/to/file", function (error, stdOut, stdErr) {
        console.log(stdOut);
        });'
    ```
