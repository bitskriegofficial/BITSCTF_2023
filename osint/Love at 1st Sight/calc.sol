// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.13 <0.9.0;

contract Calculator {

    uint c;

    function add(uint a, uint b) public {
        c = a + b;
    }

    function sub(uint a, uint b) public {
        c = a - b;
    }

    function mul(uint a, uint b) public {
        c = a * b;
    }

    function div(uint a, uint b) public {
        require(b > 0, "The second parameter should not be 0");
        c = a / b;
    }

    function getResult() public view returns (uint x) {
        return c;
    }

    function made_by_FlaireVoucher69 () public pure returns (string memory) {
        return "Welcome to the calculator. Yes, it is made by me :)";
    }
}