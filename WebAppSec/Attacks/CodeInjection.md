# **Code Injection:**

- Code executions come from a lack of filtering and/or escaping of user-controlled data.
- When you are exploiting a code injection, you will need to inject code as part of the data you are sending to the application.
- For example, if you want to run the command ls, you will need to send **system("ls")** to the application if it is a PHP application.
- **Eval** is evil in both php and ruby.
- Always remember when you are performing any code injections on a web app always try to play along with the payload and try and see if a single `'` or double `"` quotation will prompt for any errors that may give you more information.
  
  ```bash
    1. command1 || command2 : will run command2 if command1 fails
    2. command1 && command2 : will run command2 if command1 succeeds
    3. command1  ; command2 : will run command1 then command2
    4. command1  | command2 : will run command1 then send the output of command1 to command2
  ```

- If the developer has filtered out the special characters try using the backticks to run the command **`command`** or the ambassord **$(command)**

&nbsp;

- Resources:
  - [OWASP Code Injection](https://owasp.org/www-community/attacks/Code_Injection)
  - [What is Code Injection](https://www.acunetix.com/blog/articles/code-injection/)
  - [What is Code Injection and How to avoid it](https://www.netsparker.com/blog/web-security/code-injection/)
  - [Hacksplaining Code Injection](https://www.hacksplaining.com/glossary/code-injection)
