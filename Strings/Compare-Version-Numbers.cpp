public class Solution 
{
    public static int compareVersions(String a, String b) 
    {
        String[] s1 = a.split("\\.");
        String[] s2 = b.split("\\.");
        
        int maxLen = Math.max(s1.length, s2.length);
        for(int i = 0; i < maxLen; i++)
        {
            double v1 = i < s1.length ? Double.parseDouble(s1[i]) : 0;
            double v2 = i < s2.length ? Double.parseDouble(s2[i]) : 0;
            
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
        }
        return 0;
    }
}
