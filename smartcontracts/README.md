<p align="center">
  <img src="https://i.postimg.cc/0yc0vBCg/Smart-Contracts.jpg">
</p>

> [Cryptocurrency class 2022](https://cryptocurrencyclass.github.io/) coding challenges by Patrick McCorry

<details>
<summary><a href="https://cryptocurrencyclass.github.io/tutorial1.pdf">Turotial 1: A global and censorship-resistant "hello world"</a></summary><br>

  - Task 0 was focused on reading and trying to understand how the ballot smart contract program works. It is available in the [Remix IDE](https://remix.ethereum.org/) under the name `*_Ballot.sol`.
  - In this [readme](./js_script/README.md) file you will find some resources for task 0.

    <details>
    <summary>Task 1: A function that returns a string Hello World</summary><br>

    - Ropsten ETH Test Network [Transaction Hash ID](https://ropsten.etherscan.io/tx/0x292e9b790e260f6659429eeaa7048733917d5e86e4f842e4d59e1a0f46f324c9).

    ```solidity
    // SPDX-License-Identifier: GPL-3.0
    pragma solidity >=0.7.0 <0.9.0;

    contract HelloWorld {

        string message = "Hello World";

        function hello() public view returns (string memory _data)
        {
            _data = message;
        }
    }
    ```

    </details>

    <details>
    <summary>Task 2: A function that emits an event that publishes the string Hello World</summary><br>

    - Ropsten ETH Test Network [Transaction Hash ID](https://ropsten.etherscan.io/tx/0x3eafa50a967113d669ab7655c37b506c776be4a78828e33fcefe353baf2eb066)
    - Check the Logs Tab.

    ```solidity
    // SPDX-License-Identifier: GPL-3.0
    pragma solidity >=0.7.0 <0.9.0;

    contract HelloWorld {

        string message = "Hello World";
        event publishString(string);

        function hello() public returns (string memory _data) {
            _data = message;
            emit publishString(_data);
        }
    }
    ```

    </details>

    <details>
    <summary>Task 3: A function that lets anyone supply a string that will later be emitted as an event.</summary><br>

    - Ropsten ETH Test Network [Transaction Hash ID](https://ropsten.etherscan.io/address/0x153752d584b9b0132ce4ab87865398c7ee46dcdc)
    - Check under Events Tab.

    ```solidity
    // SPDX-License-Identifier: GPL-3.0
    pragma solidity >=0.7.0 <0.9.0;

    contract HelloWorld {
        
        string message = "Hello World";
        event publishString(string);

        function updateMessage(string memory Newmsg) public {
            message = Newmsg;
        }

        function hello() public returns (string memory _data) {
            _data = message;
            emit publishString(_data);
        }
    }
    ```

    - Does the gas transaction (tnx) change?
      - The gas usage is different between the two functions: `hello()` and `updateMessage()` but are constant between each tnx.
      - I can't explain why?

    </details>

    <details>
    <summary>Task 4: The function adds every new message to an array of strings.</summary><br>

    - Ropsten ETH Test Network [Contract ID](https://ropsten.etherscan.io/address/0x7f30e9a8f317c3cbe254b2a6eff4e899941a003d)

    ```solidity
    // SPDX-License-Identifier: GPL-3.0
    pragma solidity >=0.7.0 <0.9.0;

    contract HelloWorld {

        string[] messages;
        string message = "Hello World";
        event publishString(string);

        function updateMessage(string memory Newmsg) public {
            message = Newmsg;
            messages.push(Newmsg);
        }

        function hello() public returns (string memory _data) {
            _data = message;
            emit publishString(_data);
        }
    }
    ```
    
    </details>

    <details>
    <summary>Task 5: A function that keeps a record of accounts who have previously updated messages.</summary><br>

    - Ropsten ETH Test Network [Contract ID](https://ropsten.etherscan.io/address/0xe75a4e927b2de379db33dbbdbbbdc27865397e50)
    - Never found a way to iterate through the mapping, but learning on how to do so.

    ```solidity
    // SPDX-License-Identifier: GPL-3.0
    pragma solidity >=0.7.0 <0.9.0;

    contract HelloWorld {

        string lastMessage;
        address lastUser;
        mapping(address => string[]) messageStore;
        string message = "Hello World";
        event publishString(string);

        function updateMessage(string memory Newmsg) public {
            message = Newmsg;
            lastUser = msg.sender;
            lastMessage = Newmsg;
            messageStore[msg.sender].push(Newmsg);
        }

        function getMessage(address user, uint i) public view returns (string memory) {
            return messageStore[user][i];
        }

        function latestMessage() public view returns (address _user, string memory _latest) {
            _user = lastUser;
            _latest = lastMessage;
        }

        function hello() public returns (string memory _data) {
            _data = message;
            emit publishString(_data);
        }
    }
    ```
    
    </details>
        
</details>
