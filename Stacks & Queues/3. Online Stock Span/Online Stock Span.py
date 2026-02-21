class StockSpanner:

    def __init__(self):
        # Stack will store (price, span)
        self.stack = []

    def next(self, price: int) -> int:
        span = 1
        
        # Pop all smaller or equal prices
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]
        
        # Push current price and its span
        self.stack.append((price, span))
        
        return span
