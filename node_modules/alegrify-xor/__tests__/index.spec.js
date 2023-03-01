const { performance } = require('perf_hooks')
const xor = require('../index');

const casesToTest = [
  { condition1: false, condition2: false, expected: false },
  { condition1: true, condition2: false, expected: true },
  { condition1: false, condition2: true, expected: true },
  { condition1: true, condition2: true, expected: false },

  { condition1: null, condition2: null, expected: false },
  { condition1: null, condition2: true, expected: true },
  { condition1: true, condition2: null, expected: true },

  { expected: false },
  { condition2: true, expected: true },
  { condition1: true, expected: true },

  { condition1: 0, condition2: 0, expected: false },
  { condition1: 1, condition2: 0, expected: true },
  { condition1: 0, condition2: 1, expected: true },
  { condition1: 1, condition2: 1, expected: false },

  { condition1: null, condition2: 'value', expected: true },
  { condition1: 'value', condition2: null, expected: true },
  { condition1: '', condition2: NaN, expected: false },
  { condition1: {}, condition2: NaN, expected: true },
]

describe('Test conditions', () => {
  casesToTest.forEach(({ condition1, condition2, expected }) => {
    it(`${condition1} ${condition2} => ${expected}`, () => {
      expect(xor(condition1, condition2)).toBe(expected);
    });
  });
});

describe('Performance', () => {
  it('Run 999999 times under 10ms', () => {
    const start = performance.now();

    for (let i = 0; i < 999999; i++) {
      xor(false, false);
      xor(true, false);
      xor(false, true);
      xor(true, true);
    }

    const end = performance.now();

    expect(end - start).toBeLessThan(10);
  });
});