class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # I convert the input into a string 
        string_x = str(x)

        # I create a string for reversion
        reverse_string = ""

        # I reverse the string 
        for index in range(len(string_x),0,-1):
            reverse_string += string_x[index-1]

        # checking if the reversed and orginal are the same
        if reverse_string == string_x:
            return True
        else: 
            return False

a = Solution()
print(a.isPalindrome(12553))
print(a.isPalindrome(125521))