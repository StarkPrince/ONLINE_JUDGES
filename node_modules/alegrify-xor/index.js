function xor(condition1, condition2) {
  return !!condition1 + !!condition2 === 1;
}

module.exports = xor;