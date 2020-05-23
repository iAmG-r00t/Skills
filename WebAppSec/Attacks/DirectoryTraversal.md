# **Directory Traversal:**

- It comes from lack of filtering/encoding of information used as part of path by an application
- For directory traversals to work one needs to understand that you should check the path used bu the application, one does this by checking the page file or the source of the content files.

- **NB:** One thing to note is that in windows is that if you have a directory traversal you will be able to access **test/../../../../file.txt** even if the directory test does not exist but that is not the case on linux.

- A common problem when exploiting directory traversal; the server-side code adds its own suffix to your payload. This can be bypassed by using a NULL BYTE (which you will url-encode it as **%00**) to get rid of any suffix added by the server-side code is a common bypass, and works really well in Perl and older version of PHP. 
- **This bypass was fixed on the PHP version 5.3.4**