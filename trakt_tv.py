import requests
import json

base_url = "https://api.trakt.tv"
client_id = "a4c6e1b003dfc39cab00f182681d3cda4d3fcfbf85ded21820cf0b3c2f263c95"
client_secret = "f86f603a9f4da0ccc3282dff72773f2001329fbea2531ad0a7b8ded580a1488a"

header = {'Content-Type':'application/json', 
          'trakt-api-version':'2', 
          'trakt-api-key':'5d80e38e554f65169841914d27f60442ffc3939805424ad026a17c97e94bf665'}


con = json.loads(requests.get('https://api.trakt.tv/history', headers = header).text)
# dump the json data to a file
print(con)
# with open('trakt_tv.json', 'w') as f:
    # json.dump(con, f, indent=4)
