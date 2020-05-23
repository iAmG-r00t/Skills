# **PHP essential stuff:**

- In PHP we can inject simple concatenation ".", where " are used to break the syntax and reform it correctly
- Full payload: **".system('uname -a');"**
- In php, developers use **usort** to order for information and **order by** in SQL request.
  - The function **usort** is often used with the function **create_function** to dynamically generate the *"sorting"* function, based on user controlled information.
  - If the web application lacks potent filtering and validation this can lead to code execution.
  - How to execute a full payload when you realize you have found the **strcmp** function;
    - Full payload: **);}system('uname%20-a');//**

- Another dangerous modifier that exists in PHP is **PCRE_REPLACE_EVAL (/e)**, this modifier will cause the function *preg_replace* to evaluate the new value as PHP code before performing the substitution.
  - **PCRE_REPLACE_EVAL has been deprecated as of PHP 5.5.0**
  - The function assert when used incorrectly this function will evaluate the value received, this behaviour can be used to gain code execution.
  - so when one adds a ' you will see that php tried to evaluate the code. One can reconstruct the broken syntax correctly by adding the concatenation '.'
    - Full payload: **'.phpinfo().'**

- [PHP Script Paylods](Attacks/Scripts/PHP)
