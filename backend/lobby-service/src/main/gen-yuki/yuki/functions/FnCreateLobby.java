package yuki.functions;

import io.vertx.core.json.JsonArray;
import yuki.framework.dataaccess.annotations.QueryDefinitionMetadata;
import yuki.framework.dataaccess.utils.QueryDefinition;

@QueryDefinitionMetadata(sql = " SELECT * FROM fn_create_lobby( name := $1 ,secret := $2 ,admin_uuid := $3 ,nickname := $4 ) ", returnType = JsonArray.class)
public interface FnCreateLobby extends QueryDefinition {

    void setName(String name);

    void setSecret(String secret);

    void setAdmin_uuid(Object admin_uuid);

    void setNickname(Object nickname);
}
