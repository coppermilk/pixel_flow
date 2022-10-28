# The above code is reading the data from the google sheet and converting it into a csv file.
import pandas as pd
sheet_id = '1axA_i8GiCK1V7aQCcK4O5IPsjpGNsiAayjn7zziXpgA'
sheet_name = 'db'
url = f'https://docs.google.com/spreadsheets/d/{sheet_id}/gviz/tq?tqx=out:csv&sheet={sheet_name}'
df = pd.read_csv(url)
df.to_csv('out.csv', encoding='ascii')
