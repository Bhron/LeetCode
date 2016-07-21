class Solution {
    func climbStairs(n: Int) -> Int {
        if n <= 0 {
            return 0
        }
        
        if n == 1 {
            return 1
        }
        
        var F = Array(count: n + 1, repeatedValue: 0)
        F[0] = 1
        F[1] = 1
        
        for i in 2...n {
            F[i] = F[i - 2] + F[i - 1]
        }
        
        return F[n]
    }
}
