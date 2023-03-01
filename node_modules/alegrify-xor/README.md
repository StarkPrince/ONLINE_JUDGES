# XOR

[![Build Status](https://travis-ci.org/alegrify-xor/xor.svg?branch=master)](https://travis-ci.org/alegrify-xor)
[![NPM](https://img.shields.io/npm/v/alegrify-xor/latest.svg?label=npm)](https://npmjs.com/package/alegrify-xor)

Logical xor operator for JS

## Boolean table

| Condition | Condition | Output |
|-----------|–----------|--------|
| false     | false     | false  |
| false     | true      | true   |
| true      | false     | true   |
| true      | true      | false  |

## Usage

```js
const xor = require('alegrify-xor');

xor(true, false) // will return true
```