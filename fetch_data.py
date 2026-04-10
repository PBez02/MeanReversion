import yfinance as yf

ticker = yf.Ticker("AAPL")

data = yf.download("AAPL", start="2020-01-01", end="2024-01-01")

print(data.head())

data = data[["Open", "High", "Low", "Close", "Volume"]]
data.columns = ["open", "high", "low", "close", "volume"]
data.to_csv("data/prices.csv")

