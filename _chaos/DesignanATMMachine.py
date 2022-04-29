import this


class ATM:
    def __init__(self):
        self.denominations = [20, 50, 100, 200, 500]
        self.notes = {}
        for i in range(len(self.denominations)):
            self.notes[self.denominations[i]] = 0

    def deposit(self, banknotesCount):
        for i in range(len(banknotesCount)):
            self.notes[self.denominations[i]] += banknotesCount[i]

    def withdraw(self, amount):
        # get the highest denonination whose note is available
        highestDenomination = 0
        for i in range(len(self.denominations)):
            if self.notes[self.denominations[i]] > 0:
                highestDenomination = self.denominations[i]
        