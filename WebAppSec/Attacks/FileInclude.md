# **File Include:**

- File include vulnerabilities come from a lack of filtering when a user-controlled parameter is used as part of a file name in a call to an including function (require, require_once, include or include_once in PHP for example).
- If the call to one of these methods is vulnerable, an attacker will be able to manipulate the function to load his own code.
- File include vulnerabilities can also be used as a directory traversal to read arbitrary files.
- However, if the arbitrary code contains an opening PHP tag, the file will be interpreted as PHP code.
  
- File Include can cause two kinds of bugs;
  1. Local File Include: LFI. A local file is read and interpreted.
  2. Remote File Include: RFI. A remote file is retrieved and interpreted.

  - **LFI example:**
    - <https://url/example.php?page=../../../../../../../../../../etc/passwd>
  - **RFI example:**
    - <https://url/example.php?page=https://google.com>

- The same way we got rid of the suffix (for LFI) using NULL BYTE, for RFI you can get rid of the suffix by adding **&blah=** or **?blah=** depending on your URL.
- **Note that this bypass was fixed on PHP 5.3.4**

&nbsp;

- Resources:
  - [File Inclusion Vulnerabilities](https://www.offensive-security.com/metasploit-unleashed/file-inclusion-vulnerabilities/)
  - [RFI](https://www.netsparker.com/blog/web-security/remote-file-inclusion-vulnerability/)
  - [LFI](https://www.netsparker.com/blog/web-security/local-file-inclusion-vulnerability/)
  - [File Inclusion Attacks](https://resources.infosecinstitute.com/file-inclusion-attacks/)
