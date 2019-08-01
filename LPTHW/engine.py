i = 90
j = 30
v = 12.1

def print_values():
   return str(i), str(j), str(v)
  
def fail(what, what_failed):
    global eng
    global failed
    global whatfailed
    failed = what
    eng = False
    whatfailed = what_failed
    

def check_engine():   
    global eng
    if i < 100:
        if j > 28:
            if v > 12:
                eng = True
            else:
                fail(v, 'v')
        else:
            fail(j, 'j')
    else:
        fail(i, 'i')

    if eng:
        return "The engine is on."
    else:
        return f"The engine is off. {whatfailed} = {failed}"