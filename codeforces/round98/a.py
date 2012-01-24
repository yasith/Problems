if __name__ == '__main__':
    order = raw_input()

    answer = 0

    #print order
    i = 0
    while i < len(order):

        #print ""
        #print i

        cur = 0
        if order[i] == 'C':
            cur = 'P'
        else:
            cur = 'C'

        pos = order.find(cur,  i + 1)
        if pos == -1:
            pos = len(order)

        lot = order[i:pos]

        #print lot
        #print len(lot)
        #print (len(lot) + 4) / 5 

        answer += (len(lot) + 4) / 5
        #print answer

        i += len(lot)

    print answer

        
