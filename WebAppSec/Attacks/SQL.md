# **SQL Injections:**

- SQL injections are one of the common (Web) Vulnerabilities.
- SQL injections come from a lack of encoding / escaping of user-controlled input when included in SQL queries.
- Depending on how the information gets added in the query, you will need different things to break the syntax. There are different ways to echo information in a SQL statement:
  - Using quotes: single quote `'` or double quotes `"`.
  - Using back-ticks ***`*** .
  - Directly.

  - The way information is echoed back, and even what separator is used will decide the detection technique to use. (However you don't have this information, and you will need to try to guess it.)

  - Below I will be explain the payloads:
    - **Payload:** `' OR 1=1 -- [empty-space]`
      - We break the syntax using the single quote **`** (but you can use a double quote **"**)
      - We then add a `OR` keyword to make sure the comparison is always true
      - Add our always true comparison: `1=1`
      - Comment out the remaining query using  `--` (the space at the end matters, but you can use the `#` without adding a space at the end.)

    - **Payload:** `' OR 1=1 LIMIT 1#`
      - We break the syntax using the single quote **`** (but you can use a double quote **"**)
      - We then add a `OR` keyword to make sure the comparison is always true
      - Add our always true comparison: `1=1`
      - `LIMIT` number of rows/accounts to be echoed out.
      - Comment out the remaining query using  `#` (You can use `--` and make sure to add a space at the end it really matters.)
    - **Payload:** `' OR 1=1 --` **==** **`%27%09OR%091=1%09--%09`**
      - We break the syntax using the single quote **`** (but you can use a double quote **"**)
      - We then add a `OR` keyword to make sure the comparison is always true
      - Add our always true comparison: `1=1`
      - Comment out the remaining query using  `--` (the space at the end matters, but you can use the `#` without adding a space at the end.)
      - **In this Section:** the payload is the same apart from when a developer decides to block spaces the default payload won't work on would be required to intercept the request and edit the payload. When you are editing the payload you will replace the empty spaces which were interpreted as + by the browser to tabulators. Tabulation (HT or \t or `%09`) willl bypass the weak mechanism the developer has set.
      - If the developer proceeds to filter spaces and tabulations from the user input. To bypass this;
        - you need to know that you don't need spaces between the keywords in your payload injection.
        - You can use the comment sign `#` instead of -- (if necessary)
      - Another exploitable situation was dicrovered by [Christ Shiflett's Blog](http://shiflett.org/blog/2006/addslashes-versus-mysql-real-escape-string) where he talks about a way to bypass addslashes. This bypass relies on the way MySQL will perform escaping, where it will depend on the charset used by the connection and If the database driver is not aware of the charset used it will not perform the right escaping and hence creates a vurnerable situation.
      - The bypass relies on the usage of [GBK](https://en.wikipedia.org/wiki/GBK), ***GBK is a character set for simplified Chinese***.
      - Using the fact that the database driver and the database don't talk/communicate the same charset, It is possible to generate a single quote and break out of the SQL syntax to inject a payload.
      - Using the string `\xBF'` (URL-encoded as **`%bf%27`**), it's possible to get a single quote that will not get escaped properly.
      - With our string it's therefore possible to inject an always-true condition using **`%bf%27 OR 1=1 #`** and bypass authentication.
      - **How to FIX this:**
        - This issue can be fixed/remediated by setting up the connection encoding to `'GBK'` instead of using SQL query which is the source of the issue.
        - **`Note:`** It is pretty unlikely issue for a web application but it's always good to know that it exists, especially if you play **CTFs**.
  &nbsp;
  - Resources for SQL Injections:
    - [SQL Injection attacks](https://lwn.net/Articles/177037/)
  https://www.hacksplaining.com/glossary/code-injection

  &nbsp;

  - Best proxies and resources I landed by when learning SQL Injection:
    - [BurpSuite](https://portswigger.net/burp)
    - [FoxyProxy - Proxy Management Tool](https://addons.mozilla.org/en-US/firefox/addon/foxyproxy-standard/)
    - [TamperChrome Chrome's Web Proxy](https://github.com/google/tamperchrome)
    - [HTTPIE works like Curl but easy](https://github.com/jakubroztocil/httpie)