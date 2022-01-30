class Solution {
    public String defangIPaddr(String address) {
        String defangedIPaddr = "";
        defangedIPaddr = address.replace(".", "[.]");
        
        return defangedIPaddr;
    }
}
