dict = {}
sentence = 'edjskdjsaldkajs sajdkalsdj asjdklsadjkldsaj kal'
sentence = [w for w in sentence.split(' ')]
for w in sentence:
  dict[w] = 1

for w in dict:
  print(w, dict[w])