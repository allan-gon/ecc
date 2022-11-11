MAXAMOUNT = 500000


def get_price_day_of(day: int, ledger: dict) -> int:
    price_at_day_of_trade = None
    for d in ledger:
        if d > day:
            break
        price_at_day_of_trade = ledger[d]
    return price_at_day_of_trade


class Trade:
    
    def __init__(self, name:str, day: int, amount: int, bought: bool) -> None:
        self.name = name
        self.day = day
        self.amount = amount
        self.bought = bought

    def __str__(self):
        return f"Day: {self.day}, Amount: {self.amount}, Bought: {self.bought}"


    def is_sus(self, ledger: dict) -> bool:
        """Checks if a single trade is sus"""
        # when did the trade happen
        # in the following three days did they make >= 500k
        
        # a trade can happen on a day whose price
        # id not explicitly listed in the ledger
        # if that's the case. the price is the most recent days price
        price_at_day_of_trade = get_price_day_of(self.day, ledger)
        # if bought, did they sell in the next 3 days
        latest_price = get_price_day_of(self.day + 3, ledger)
        if self.bought:
            if ((latest_price - price_at_day_of_trade) * self.amount) >= MAXAMOUNT:
                return True
        elif ((price_at_day_of_trade - latest_price) * self.amount) >= MAXAMOUNT:
            return True
        return False


def find_sus(ledger: dict, trades: list[Trade]) -> list[str]:
    sus_map = dict()

    for trade in trades:
        if trade.is_sus(ledger):
            if trade.name not in sus_map:
                sus_map[trade.name] = trade.day
    return sorted([f"{sus_map[key]}|{key}" for key in sus_map], key=lambda x: (x.split("|")[0], x.split("|")[1]))


def main():
    # read trades from file
    with open("./input.txt", "r") as file:
        content = file.read().splitlines()
    # parse content
    ledger = {}
    trades = []
    for line in content:
        temp_inp = line.split("|")
        if len(temp_inp) == 2: # if a day|price combo
            ledger[int(temp_inp[0])] = int(temp_inp[1])
        else:
            trades.append(Trade(temp_inp[1], int(temp_inp[0]), int(temp_inp[3]), temp_inp[2] == "BUY"))
    sus_accs = find_sus(ledger, trades)
    print(sus_accs)
    return


if __name__ == "__main__":
    main()

# if you buy and in <= 3 days the price goes up,
# if the "profit" you made (simply by have stock at the right time)
# if >= max thats sus

# if you sell and in <= 3 days the prices goes down,
# if the "loss" you prevented (simply by dumping before a crash)
# is >= max that sus

# sus is buy and price goes up and amount bought * difference in price >= max
# sus if sell and price goes down and amount sold * difference in price >= max
