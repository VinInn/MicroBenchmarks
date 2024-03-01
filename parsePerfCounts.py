def parseOne(fname) :
  nop=0
  d ={}
  with open(fname) as f:
    print('\n\n## '+fname)
    for line in f:
      try:
        (wf, val, key) = line.split()
        d[wf] = {}
      except:
        nop+=1
  with open(fname) as f:
    for line in f:
      try:
        (wf, val, key) = line.split()
        d[wf][key]= float(val)*1.e-9
        if (key=='task-clock') : d[wf][key] = float(val)
       	if (key=='duration') : d[wf][key] = float(val)
      except:
        nop+=1
#
  do = {}
  for wf in d :
    for k in d[wf] :
      ko = k
      if not ko in do : do[ko] = {}
      do[ko][wf] = d[wf][k]
  return do

def doPrint(di) :
  s = '| counter |'
  for wf  in di['cycles'] :
    s+= ' ' + wf + ' |'
  print(s)
  s = '| :---- | '
  for wf  in di['cycles'] :
    s+= ' :----: |'
  print(s)
  for k in di :
    s = '| ' + k + ' |'
    for wf  in di[k] :
        v = di[k][wf]
        s+= ' ' + "{:6.4f}".format(v)  + ' | '
    print(s)


doPrint(parseOne('data/fileToParse'))
