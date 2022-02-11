import requests
prince = "https://clist.by:443/api/v2/coder/13939/?username=StarkPrince&api_key=784208bd2b69ff67c4b08b8418114ca47eeaccf0"

data = requests.get(prince)
data = data.json()
print(data)
