#!/usr/bin/python -tt

num_to_word = { 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine',
        10:'ten', 11:'eleven', 12:'twelve', 13:'thirteen', 14:'fourteen', 15:'fifteen', 16:'sixteen', 17:'seventeen',
        18:'eighteen', 19:'nineteen', 20:'twenty', 30:'thirty', 40:'forty', 50:'fifty', 60:'sixty', 70:'seventy',
        80:'eighty', 90:'ninety' }
num_to_letter_count = { 1:3, 2:3, 3:5, 4:4, 5:4, 6:3, 7:5, 8:5, 9:4, 10:3, 11:6, 12:6, 13:8, 14:8, 15:7, 16:7, 17:9, 18:8, 19:8,
        20:6, 30:6, 40:5, 50:5, 60:5, 70:7, 80:6, 90:6 }

total_count = 0
for i in range(1,1000):
    str_pr = ''
    count = 0
    if (i in num_to_word):
        str_pr = num_to_word[i]
        count += num_to_letter_count[i]
    else:
        c = i % 10
        b = (i / 10) % 10
        a = (i / 100) % 10
        
        if (b == 1):
            str_pr += num_to_word[10 + c]
            count += num_to_letter_count[10 + c]
        elif (b > 1):
            str_pr += num_to_word[b * 10] 
            count += num_to_letter_count[b * 10]
            if (c > 0):
                str_pr += '-' + num_to_word[c]
                count += num_to_letter_count[c]
        elif (c > 0):
            str_pr += num_to_word[c]
            count += num_to_letter_count[c]

        if (a > 0):
            if str_pr:
                str_pr = num_to_word[a] + ' hundred and ' + str_pr 
                count += num_to_letter_count[a] + 10
            else:
                str_pr = num_to_word[a] + ' hundred'
                count += num_to_letter_count[a] + 7
    total_count += count
    print str(i) + ': ' + str_pr + ' - ' + str(count) + ' - ' + str(total_count)
print total_count + 11
