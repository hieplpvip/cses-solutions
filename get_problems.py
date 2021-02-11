import requests

src = requests.get('https://cses.fi/problemset/list/').text

ind = 0
while True:
  start = src.find('<a href="/problemset/task/', ind)
  if start == -1:
    break
  end = src.find('</a>', start)

  pid = src[start + len('<a href="/problemset/task/'):start + len('<a href="/problemset/task/') + 4]
  name = src[start + len('<a href="/problemset/task/') + 6: end]
  print('| [%s](https://cses.fi/problemset/task/%s/) | |' % (name, pid))

  ind = end
