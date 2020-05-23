# **XML Attacks:**

- In XML attacks some XML parsers will resolve external entities, and will allow a user controlling the XML message to access resources.
- The payload below is an entity which can be declared to read a file on the system. `<!ENTITY x SYSTEM "file:///etc/passwd">`
- This mainly works because most devs don't disable DTD feature.
- But the above payload is not yet complete, you need to envelope it properly to get it working. Where we will do so as below:

    ```bash
      <!DOCTYPE test [
        <!ENTITY x SYSTEM "file:///etc/passwd">]>
    ```

  - But the payload can't work directly one needs to execute it, hence we add the below variable at the end of the payload, hence the full payload will be:
  (**URL Encode the ambassord sign, if you pass it that way on the web application it will not work.** URL-Encoded will be **`%26`**)

   ```bash
      <!DOCTYPE test [
        <!ENTITY x SYSTEM "file:///etc/passwd">]>
        <foo>&x;</foo>
    ```
  
  - In XML attacks there is one attack known as XPATH. Where XPath is a query language, which selects nodes from an XML document.
  - Imagine the XML document as a database, and XPath as an SQL query. If you can manipulate the query, you will be able to retrieve elements to which you normally should not have access.

  &nbsp;

  - Below I am going to explain the payload step by step:
    - Given that we have such a URL: ![image](https://user-images.githubusercontent.com/29776892/82720148-5d837300-9cb9-11ea-94e6-6fe8abb209a5.png)
    - Carefully analyzing the URL it looks like this is an SQL injection attack present because its more of a username and password meaning we have a database present, but if you place a single comma `'` either after the username e.g: **`username=hacker' or password=test'`**, you will see an error code showing you that you are dealing with an `xpath`.
    - This being the case, we need to complete our syntax to fix that error, in XPath adding the `]` will properly complete the syntax and the error code will be fixed.
    - Next is trying to figure how to kill the rest of the chain so that our payload should work, this is usually done because if we are injecting our query payload within the username field we need to kill the rest of the chain which is for password check so that our payload to work perfectly. and we achieve this by adding the **NULL BYTE** `%00` at the end of the syntax.
    - With this three information we can now go and inject our payload;
      - **Payload:** 
        - When creating a payload we need to look at XPath as a tree. This **`']/parent::*%00`** payload what it basically does it says from that node we want the parent of test, where it is basicaly going to take as one step back. **NB:** The payload may not produce any output.
        - This **`']/parent::*/child%00`** payload now says we want the child of the parent of test. **NB:** The payload may not produce any output.
        - This **`']/parent::*/child::node()%00`** payload now selects the node to get the actual content, in this section what it basically does it provides all the values of the other parents next to **test** parent.(It will provide all the usernames.)
        - Our XPath syntax is now complete, but now we need to try and inject an always true function which is `OR 1=1` where its going to select each node and its content.
          - Complete payload: **`' or 1=1]/parent::*/child::node()%00`**
        - Lets say one want to inject and get the password for admin, you will only need to change the username from test to admin and remove the always true function. where payload will look like this: **`/?name=admin']/parent::*/child::node()%00`**

  &nbsp;
  - Resources on XML Attacks:
    - [XML Based Attacks](https://owasp.org/www-pdf-archive/XML_Based_Attacks_-_OWASP.pdf)
    - [XML external entity (XXE) injection](https://portswigger.net/web-security/xxe)
    - [What Are XML External Entity (XXE) Attacks](https://www.acunetix.com/blog/articles/xml-external-entity-xxe-vulnerabilities/)
