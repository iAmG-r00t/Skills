# Strings to bytes32

- Voting Smart contract task in the [Solidity by Example](https://docs.soliditylang.org/en/v0.8.13/solidity-by-example.html).

- Youtube Guide; [Solidity by Example - Deploying a Voting Smart Contract](https://www.youtube.com/watch?v=GB3hiiNNDjk)

- bytes32 are more effecient and use less gas than strings.

> You can use `ethers` **Node.js** module to convert a string to bytes32 or this [site](https://profitplane.com/str-to-bytes32).

## Setup

- Run below commands to setup enviroment using a docker container.

```sh
# pull npm docker image and start a container
docker pull node
docker run -it --rm -v $PWD/js_script:/root/ node:latest /bin/bash

# inside the docker container
npm init --y
npm install ethers

# create bytes32 from string
node createBytes.js <string-name>

# parse bytes32 to string
node parseBytes.js <bytes32-string>
```
