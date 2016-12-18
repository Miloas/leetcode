/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let st = [] 
    for(let i = 0; i < s.length; ++i) {
      if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i])
      else {
        let t = st.pop() 
        if(s[i]==')'&&t=='(') continue
        if(s[i]==']'&&t=='[') continue
        if(s[i]=='}'&&t=='{') continue 
        return false
      }
    }
    if(st.length != 0) return false
    return true
};