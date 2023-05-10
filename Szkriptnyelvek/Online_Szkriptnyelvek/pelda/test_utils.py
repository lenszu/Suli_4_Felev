from utils import duplaz, is_palindrome


def test_duplaz():
    assert duplaz(2) == 4
    assert duplaz(4) == 8
    assert duplaz(6) == 12
    
    

def test_ispalindrome():
    assert is_palindrome("anna") == False
    
