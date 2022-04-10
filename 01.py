def XOR(dataword):
    dataword = list(map(int, dataword))
    check = 0
    for i in range (len(dataword)):
        check+=dataword[i]
    
    if check%2==0:
        return 0
    else:
        return 1




def parity_check(codeword,number_parity_bit):
    print(f'number of parity bit = {number_parity_bit}')
    
    codeword.reverse()
    print("codeword = %s" %(codeword))
    for i in range(number_parity_bit+1):
        paritybit = 0
        arr_of_bit  = []
        for j in range(len(codeword)):
            # print(f'codeword[j] = {codeword[j]}')
            if codeword[j] != -1:
                binary = list(bin(j+1))
                # print(f'Binary before = {binary}')
                # binary.pop(0)
                # binary.pop(0)
                # binary.reverse()
                # list(map(int, binary))
                print(f'Binary = {binary}, parity bit ที่ i = {i}')
                if(len(binary) - 2 >= i and binary[-(i+1)] != 'b' and int(binary[-(i+1)]) == 1):
                    # paritybit+=codeword[j]
                    arr_of_bit.append(codeword[j])
                    print("----------------------------------")
        print(f'bit ที่เอามาคิด {arr_of_bit} arr_of_bit.count(1) = {arr_of_bit.count(1)}  แลำ party bit ที่ {2**i} ขอว codeword i = {i}') 
        if(arr_of_bit.count(1)%2 == 0):
            codeword[2**i-1] = 0
            # print(f'i = {i}')
        else:
            codeword[2**i-1] = 1
            # print(f'i = {i}') 
    return codeword


                    



def Hamming_gen(dataword):
    dataword = list(map(int, dataword))
    dataword.reverse()
    #print(len(dataword))
    codeword=[]
    index_dataword = 0
    power_check = 0
    index_check = 1
    while index_dataword != len(dataword):
        #print('while')
        if(2**power_check == index_check):#ใส่ parity bit
            binary = list(bin(index_check))
            binary
            codeword.append(-1)
            index_check+=1
            power_check += 1

        else:#ใส่ dataword 
            codeword.append(dataword[index_dataword])
            index_check+=1
            index_dataword+=1

    codeword.reverse()
    codeword = parity_check(codeword,power_check-1)
    return codeword




_dataword='01100011'
print(Hamming_gen(_dataword))  

            