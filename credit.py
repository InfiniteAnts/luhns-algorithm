import cs50

def main():
    
    # User prompt for credit card number
    while True:
        print("Number: ", end="")
        cc = cs50.get_int()
        if cc >= 0:
            break
    
    cc2 = cc
    cc3 = cc
    cc4 = cc
    
    # Checksum    
    c = 0
    
    # dividing and modding by 10 to get 2nd last digit
    cc //= 10
    
    while cc != 0:
        z = cc % 10
        
        # Multiplying digits by 2
        z *= 2
        
        # Sum of product's digits
        for i in range(2):
            a = z % 10
            c += a
            z //= 10
            
        # Dividing by 100 to get every other digit
        cc //= 100
    
    while cc2 != 0:
        
        # Modding by 10 to get the last digit
        z = cc2 % 10
        
        # Adding digits to the previous sum of product's digits
        c += z
        
        # Dividing by 100 to get every other digit
        cc2 //= 100
    
    # Setting a validity flag if checksum is passed
    if c % 10 == 0:
        valid = True
    else:
        valid = False
        
    # If validity flag is false, invalid is displayed
    if not valid:
        print("INVALID")
        
    #digitsn holds the number of digits in the credit card number
    digitsn = 0
    
    while cc3 != 0:
        cc3 //= 10
        digitsn += 1
    
    amexid = cc4 // 10 ** 13
    
    if valid and digitsn == 15 and (amexid == 34 or amexid == 37):
        print("AMEX")
        
    mastid = cc4 // 10 ** 14
    
    if valid and digitsn == 16 and (mastid == 51 or mastid == 52 or
                                    mastid == 53 or mastid == 54 or
                                    mastid == 55):
        print("MASTERCARD")
    
    visaid = cc4 // 10 ** 12
    visaid2 = cc4 // 10 ** 15
    
    if valid and ((digitsn == 13 and visaid == 4) or 
                  (digitsn == 16 and visaid2 == 4)):
        print("VISA")
        
if __name__ == "__main__":
    main()